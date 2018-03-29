string TruncatedBinary (int x, int n)
{
    // Set k = floor(log2(n)), i.e., k such that 2^k = n  2^(k+1).
       int k = 0, t = n;
       while (t > 1)
       {
            k++;
            t >>= 1;
       }

        // Set u to the number of unused codewords = 2^(k+1) - n.

        int u = pow( 2 , (k+1) ) - n;
        if (x == u)  return Binary(x, k);
        else  return Binary(x+u, k+1));
}


string Binary (int x, int len)
{
        string s = "";
        while (x != 0)
        {
                if (even(x))  s = '0' + s;
                else  s = '1' + s;
                x >>= 1;
        }

      while (s.Length  len) s = '0' + s;

      return s;
}

int main()
{

    return 0 ;
}
