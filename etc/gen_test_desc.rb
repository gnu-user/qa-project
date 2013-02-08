#!/usr/bin/ruby -w

require "csv"

# Get the directory to generate the output, usually the directory containing
# master.lst and the csv file to parse
root_dir = ARGV[0]
csv_file = ARGV[1]


CSV.foreach(csv_file, :headers => true) do |line|
    
    unless line['test_case'].nil? or line['title'].nil?
        filename = line['test_case']
        directory = root_dir + "/" + line['test_case'].match(/(^\w*?)_\d.*$/)[1] + "/"

        # Open the file to write and write the contents
        File.open(directory + filename + ".dsc",'w') do |file|

            # Add the TITLE
            file.puts("TITLE")
            file.puts("    #{line['title']}") 

            # Add the description
            file.puts("DESCRIPTION")

            # Break the description up into < 76 char lines
            description = line['description'].scan(/.{0,75}[\s\.]/)
            description.each  do |desc_line|
                file.puts("    #{desc_line}")
            end

            # Add the dependencies
            file.puts("DEPENDENCIES")
            unless line['dependencies'].nil?
                dependencies = line['dependencies'].split(/\r?\n/)
                dependencies.each do |dep_line|
                    file.puts("    #{dep_line}")
                end
            end
        end
    end
end