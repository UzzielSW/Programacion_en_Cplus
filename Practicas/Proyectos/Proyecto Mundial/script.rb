def main
	# printf("\narchivo: ")
	# namefl = gets.chomp
	fil = File.open("test.txt", "w+")

	File.foreach("eq.txt") { |line| 
		arr = line.split("\" ")
		arr[0].delete!('"')
		fil.puts("{ \"#{arr[0]}\", #{arr[1]} },\n")
	}

	fil.close
	gets
end

main()