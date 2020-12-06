for ((i = 1; ; ++i)); do
	echo $i
	./gentree $i > int
	diff -w <(./maxflow < int) <(./brute < int) || break
done
