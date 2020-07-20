for ((i = 170; ; ++i)); do
	echo $i
	./gen_tree $i > int
	diff -w <(./barnpainting < int) <(./brute < int) || break
done
