for i in a b c d e f;
do
   ./main < ${i}.txt #> t_${i}.txt
done
