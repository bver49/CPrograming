for i in {1..20}; 
do ./H34026246_HW5 0 10000 1 10000 $i >> result.txt
done

for i in {1..20}; 
do ./H34026246_HW5 0 10000 10000 30000 $i >> result.txt
done

for i in {1..20}; 
do ./H34026246_HW5 0 10000 1 30000 $i >> result.txt
done

for i in {1..20}; 
do ./H34026246_HW5 0 50000 1 50000 $i >> result.txt
done

for i in {1..20}; 
do ./H34026246_HW5 0 50000 20000 70000 $i >> result.txt
done

for i in {1..20}; 
do ./H34026246_HW5 0 50000 1 70000 $i >> result.txt
done

for i in {1..20}; 
do ./H34026246_HW5 0 100000 1 100000 $i >> result.txt
done

for i in {1..20}; 
do ./H34026246_HW5 0 100000 50000 150000 $i >> result.txt
done

for i in {1..20}; 
do ./H34026246_HW5 0 100000 1 150000 $i >> result.txt
done