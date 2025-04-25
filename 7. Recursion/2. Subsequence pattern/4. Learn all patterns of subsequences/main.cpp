print all subsequences with sum k
(theory)

same as clculating the power set which we normaly using    either pick or not pick 

we just have to mantain an extra variable calles sum

which we will have to handle during backtracking also  

//print any subsequence whose sum is k

1. we can be smart enough by mantainng a boolean flag variable 
2. functional methods use karo => pick and non pick 
    => if you are able to check if we already got such a  subsequence no need to go for the other recursive call 

Technique to print only one subseqyence => base case => if condition satisfied => return true else false 

    doing this before doing the recursive call will make sure we have the ans;


//just give me the count
in the base case return 1 if c ondition satisfies else return 0

l = ();
r = ();

return l + h; as the final answer