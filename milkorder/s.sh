for ((i = 1; ; ++i)); do
	echo $i
	./gen $i > int
	diff -w <(./milkorder < int) <(./brute < int) || break
done
