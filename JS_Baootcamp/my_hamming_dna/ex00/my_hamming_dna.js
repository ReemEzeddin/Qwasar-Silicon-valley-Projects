function my_hamming_dna(dna1,dna2)
{
    if (dna1.length != dna2.length)
        return (-1);
    counter = 0;
    for (var i = 0; i < dna1.length; i++)
    {
        if (dna1[i] != dna2[i])
            counter++;
    }
    return (counter);
}