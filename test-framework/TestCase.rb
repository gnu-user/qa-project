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


# The test case class
class TestCase
	attr_accessor	:name, 
					:title, 
					:description, 
					:dependencies,	# Array of test case dependencies
					:status			# Status of test case, pass, fail, or unmet dependencies

	def initialize(name)
		@name = name
		@dependencies = []
	end

	# Parses the test case description file and stores the TITLE, DESCRIPTION,
	# and DEPENDENCIES content
	def parse_description(root_dir, test_suite)
		content = ""
		file_path = "#{root_dir}/#{test_suite}/#{@name}.dsc"
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

	# Sets the status for the test case, which can be one of the following
	# Passed, Failed, or Unmet Dependencies
	def set_status(status)
		@status = status
	end
end
