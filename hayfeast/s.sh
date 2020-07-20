for ((i = 1; i < 2; ++i)); do
	echo $i
	./gen $i > int
	./hayfeast < hayfeast.in > out1
	#diff -w <(./barnpainting < int) <(./brute < int) || break
done
