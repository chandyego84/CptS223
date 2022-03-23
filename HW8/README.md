# Assignment 8: Array vs. Balanced BST vs. Hash Table (Search Running Times)

For N = 1 to Nmax:
<ol>
<li>Create array A of size N that contains the integers 1...N in random order</li>
<li>Create a new instance of each of the three STL data structures: vector V, set S, 
unordered_set US</li>
<li>Insert the integers from A, in order from A[0] to A[N-1], into each of V, S, US</li>
<li>For each data structure D in {V, S, US}</li>
    <ol>
        <li>Record startTime</li>
        <li>Search D for each integer in A, in order from A[0] to A[N-1]</li>
        <li>Record endTime</li>
        <li>averageTimeD = (endTime – startTime) / N</li>
    </ol>
<li>Output CSV line: N, averageTimeV, averageTimeS, averageTimeUS</li>
<li>Delete instances V, S, US</li>
</ol>