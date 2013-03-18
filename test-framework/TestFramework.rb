#!/usr/bin/env ruby
###############################################################################
#
#  Swift Ticket -- Test Framework
# 
#  Copyright (C) 2013, Jonathan Gillett, Daniel Smullen, and Rayan Alfaheid
#  All rights reserved.
# 
# 
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
# 
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
# 
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
###############################################################################
require './TestSuite'
require './TestCase'
require './colorize'


# Simple function which verifies if a test case or test suite
# has unmet dependencies, which is any test case or test suite that
# has been executed, but has not passed
def unmet_dependencies?(test, test_history)
	test.dependencies.each() do |dependency|
		# If the test dependency has been executed and failed return true
		if test_history.has_key?(dependency) and test_history[dependency].status != "Passed"
			return true
		end
	end

	return false
end


# Yields a list of the unmet dependencies, these are dependencies for the test case
# or test suite that have failed.
def failed_dependencies(test, test_history)
	test.dependencies.each() do |dependency|
		# Yield each test dependency that failed
		if test_history.has_key?(dependency) and test_history[dependency].status != "Passed"
			yield test_history[dependency] 
		end
	end
end


# Diffs the two files specified and saves the results to a .diff file in the same
# directory as the second file that is being compared
def diff_files(file_1, file_2)
	output_file = file_2.sub(/\.test$/, '')
	system("diff -scbBa #{file_1} #{file_2} " +
	   	   "| sed -e 's/\\\\ No newline at end of file$//g' > #{output_file}.diff")
end


# Array of test suites to execute, the master test list
master_testlist = []

# History of each test case and suite executed and the result
test_history = {}


# Parse the command line arguments, ensure that each argument is valid
if ARGV.length <  3
	abort("Invalid number of arguments provided!\n" +
		  "USAGE:   TestFramework.rb [front end binary] [test suite directory] [output directory]\n" +
		  "EXAMPLE: TestFramework.rb ../FrontEnd/Debug/FrontEnd ../tests ../tests/output")	
end

ARGV.each() do |argument|
	unless File.exists?(argument)
		abort("Invalid argument, #{argument} does not exist!")
	end
end

binary_path = ARGV[0]
tests_path = ARGV[1]
output_path = ARGV[2]


# Parse each test suite and all test cases and store the objects
# in the master test list array
if File.exists?("#{tests_path}/master.lst")
	File.readlines("#{tests_path}/master.lst").each do |line|
		# Ignore comments and skipped test suites
		if (line =~ /^[\#@].*$/)
			next
		else
			test_suite = TestSuite.new(line.strip)
			test_suite.parse_description(tests_path)
			test_suite.parse_testlist(tests_path)

			master_testlist << test_suite
		end
	end
else
	raise "#{tests_path}/master.lst not found!"
end


# Execute each test suite and verify that the test suite dependencies have been met
master_testlist.each() do |test_suite|
	puts "\n\nExecuting #{test_suite.title}"
	printf "%-40s\n", "=" * 40

	# The path to the test case and results
	test_path = "#{tests_path}/#{test_suite.name}"
	result_path = "#{output_path}/#{test_suite.name}"

	# Add each test suite executed to the test history
	test_history[test_suite.name] = test_suite
	
	# If test suite dependencies that have not been met, test suite cannot be executed
	if unmet_dependencies?(test_suite, test_history)

		test_suite.set_status("Unmet Dependencies")
		
		printf "%-70s %s\n", test_suite.title, "FAILED".red
		puts "Failed due to the following unmet dependencies:".light_cyan
		
		failed_dependencies(test_suite, test_history) do |dependency|
			puts "#{dependency.title}".yellow
		end

		# Display the horizontal bar at bottom of test suite results
		printf "%-40s %s %s\n", "-" * 40, " " * 28, "-" * 8
		printf "%-70s %s\n", test_suite.title, "FAILED".red

		next
	end


	# Create a corresponding output directory for test suite results
	unless File.directory?(result_path)
		Dir.mkdir(result_path)
	end


	# Execute each test case and save the console output and daily transaction file
	test_suite.test_cases.each() do |test_case|

		# Path to the test case input directory and test case
		test_file = "#{test_path}/#{test_case.name}"
		result_file = "#{result_path}/#{test_case.name}"
		out_status = 0
		dtf_status = 0

		# Add each test case executed to the test history
		test_history[test_case.name] = test_case

		# If test case dependencies that have not been met, test suite cannot be executed
		if unmet_dependencies?(test_case, test_history)
			
			test_case.set_status("Unmet Dependencies")

			printf "%-70s %s\n", test_case.title, "FAILED".red
			puts "Failed due to the following unmet dependencies:".light_cyan
			
			failed_dependencies(test_case, test_history) do |dependency|
				puts "#{dependency.title}".yellow
			end

			next
		end

		# Execute the test case and save the console output
		system("#{binary_path} #{test_file}.cua #{test_file}.atf #{result_file}.dtf " +
			   " < #{test_file}.inp &> #{result_file}.out")

		# Diff the expected console output and the daily transaction file
		# if there are any differences the test case has failed
		system("diff -sbBaq #{test_file}.out #{result_file}.out > /dev/null")
		out_status = $?.exitstatus

		# Diff the daily transaction files if one was created
		unless File.zero?("#{test_file}.dtf")
			system("diff -sbBaq #{test_file}.dtf #{result_file}.dtf > /dev/null")
			dtf_status = $?.exitstatus
		end

		# The test case failed if console output or daily transaction files differ
		if out_status != 0 or dtf_status != 0
			# Display the results of the test case, set test case status
			printf "%-70s %s\n", test_case.title, "FAILED".red
			test_case.set_status("Failed")

			# If the daily transaction files differ save the diff output
			if dtf_status != 0
				diff_files("#{test_file}.dtf", "#{result_file}.dtf")
			end

			# If the console output differs save the diff output
			if out_status != 0
				diff_files("#{test_file}.out", "#{result_file}.out")
			end
		else
			# Display the results of the test case, set test case status
			printf "%-70s %s\n", test_case.title, "PASSED".green
			test_case.set_status("Passed")
		end
	end

	# Display the summary of pass or fail for each test suite
	test_suite.test_cases.each() do |test_case|
		if test_case.status != "Passed"
			test_suite.set_status("Failed")
			break
		end
	end

	# Display the horizontal bar at bottom of test suite results
	printf "%-40s %s %s\n", "-" * 40, " " * 28, "-" * 8

	if test_suite.status.nil?
		test_suite.set_status("Passed")
		printf "%-70s %s\n", test_suite.title, "PASSED".green
	else
		printf "%-70s %s\n", test_suite.title, "FAILED".red
	end
end