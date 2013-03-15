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


# The main test suite class
class TestSuite
	attr_accessor 	:name, 
					:title, 
					:description, 
					:depenedencies,	# Array of test suite dependencies 
					:test_cases,	# Array of test cases for the test suite
					:status			# Status of test suite, pass, fail, or unmet dependencies

	def initialize(name)
		@name = name
		@depenedencies = []
		@test_cases = []
	end

	# Parses the test suite description file and stores the TITLE, DESCRIPTION,
	# and DEPENDENCIES content
	def parse_description(root_dir)
		content = ""
		file_path = "#{root_dir}/#{@name}/#{@name}.dsc"

		# Parse the contents of the file
		if File.exists?(file_path)
        	File.readlines(file_path).each do |line|
    			if (line =~ /^TITLE\n$/)
    				next
    			elsif (line =~ /^DESCRIPTION\n$/)
    				@title = content.strip
    				content = ""
    			elsif (line =~ /^DEPENDENCIES\n*$/)
    				@description = content
    				content = ""
				else
					content += line.lstrip
    			end
    			# Set the list of test suite dependencies
    			@dependencies = content.split('\n')
        	end
        else
        	raise "File: #{file_path} not found!"
        end
	end

	# Parses the list of test cases and stores each test case in an array
	def parse_testlist(root_dir)
		file_path = "#{root_dir}/#{@name}/#{@name}.lst"

		if File.exists?(file_path)
			File.readlines(file_path).each do |line|
				# Ignore comments and test prefixed with "@", which are to be skipped
				if (line =~ /^[\#@].*$/)
					next
				else
					# Add each test case object to the array
					test_case = TestCase.new(line.strip)
					test_case.parse_description(root_dir, @name)
					@test_cases << test_case
				end
			end
		else
			raise "File: #{file_path} not found!"
		end
	end
end