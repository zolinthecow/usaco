for ((i = 1; ; ++i)); do
	echo $i
	./gen $i > int
	./fenced < int > out1
done
