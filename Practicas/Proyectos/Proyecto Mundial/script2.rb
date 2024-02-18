def main
	# printf("\narchivo: ")
	# namefl = gets.chomp
	fil = File.open("test.txt", "w+")

	File.foreach("eq.txt") { |line| 
		line.delete!("\n")

		if line.include?("\"")
			arr = line.split("\" ")
			arr[0].delete!('"')
			fil.print("\n{ \"#{arr[0]}\", #{arr[1]}},")
		else
			if line.length > 1
				fil.printf(" \"#{line}\",")
			else
				fil.printf(" \'#{line}\',")
			end
		end

	}

	fil.close
	gets
end

main()