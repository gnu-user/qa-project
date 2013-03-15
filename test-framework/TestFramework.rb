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


# Array of test suites to execute, the master test list
master_testlist = []

# History of each test case and suite executed and the outcome
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


#test = TestSuite.new("login")
#test.parse_description("../tests")
#test.parse_testlist("../tests")

master_testlist.each() do |test_suite|
	puts "-----------------------------------------------"
	puts test_suite.name
	puts test_suite.title
	puts test_suite.description
	puts test_suite.depenedencies
	puts "\n"
	
	test_suite.test_cases.each() do |test_case|
		puts test_case.name
		puts test_case.title
		puts test_case.description + "\n"
	end
	puts "\n\n" 
end