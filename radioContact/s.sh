for ((i = 1; ; ++i)); do
	echo $i
	./gen $i > int
	./radioContactBrute < int > out1
	./radioContact < int > out2
	diff -w out1 out2 || break
done
