for ((i = 1; ; ++i)); do
	echo $i
	./gen $i > int
	#./hayfeast < hayfeast.in > out1
	diff -w <(./threesum < int) <(./brute < int) || break
done
