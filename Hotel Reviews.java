/*
Given a set of reviews provided by the customers for different hotels and a string containing “Good Words”, you need to sort the 
reviews in descending order according to their “Goodness Value” (Higher goodness value first). We define the “Goodness Value” of a 
string as the number of “Good Words” in that string.

Constraints:

1.   1 <= No.of reviews <= 200
2.   1 <= No. of words in a review <= 1000
3.   1 <= Length of an individual review <= 10,000
4.   1 <= Number of Good Words <= 10,000
5.   1 <= Length of an individual Good Word <= 4
6.   All the alphabets are lower case (a - z)

Input:
S : A string S containing "Good Words" separated by  "_" character. (See example below)
R : A vector of strings containing Hotel Reviews. Review strings are also separated by "_" character.

Output:
A vector V of integer which contain the original indexes of the reviews in the sorted order of reviews. 
V[i] = k  means the review R[k] comes at i-th position in the sorted order. (See example below)
In simple words, V[i]=Original index of the review which comes at i-th position in the sorted order. (Indexing is 0 based)

Example:

Input: 
S = "cool_ice_wifi"
R = ["water_is_cool", "cold_ice_drink", "cool_wifi_speed"]

Output:
ans = [2, 0, 1]
Here, sorted reviews are ["cool_wifi_speed", "water_is_cool", "cold_ice_drink"]

*/
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
public class Trie
{
    public class IntPair 
    {
        final int x;
        final int y;
        IntPair(int x, int y) {this.x=x;this.y=y;}
        public int getx()
        {
            return x;
        }
        public int gety()
        {
            return y;
        }
    }
    public ArrayList<Integer> solve(String A, ArrayList<String> B) 
    {
        String words[]=A.split("_");
        HashSet<String> st=new HashSet<String>();
        for(String s:words) st.add(s);
        List<IntPair> map = new ArrayList<IntPair>();
        int mn=Integer.MAX_VALUE,mx=Integer.MIN_VALUE;
        for(int i=0;i<B.size();i++)
        {
            String word[]=B.get(i).split("_");
            int cnt=0;
            for(String s:word) if(st.contains(s)) cnt++;
            if(mn>cnt) mn=cnt;
            if(mx<cnt) mx=cnt;
            map.add(new IntPair(cnt,i));
        }
        Collections.sort(map,new Comparator<IntPair>()
        {
            @Override
            public int compare(IntPair a,IntPair b)
            {
               return b.getx()-a.getx();
            }
        });
        ArrayList<Integer> ans=new ArrayList<Integer>();
        for(int i=0;i<map.size();i++) 
        {
            ans.add(map.get(i).y);
        }
        return ans;
    }
    public static void main(String args[])
    {
        Trie t=new Trie();
        String A = "cool_ice_wifi";
        ArrayList<String> B = new ArrayList<>(Arrays.asList("water_is_cool", "cold_ice_drink","cool_wifi_speed","cool_ice","cool_ice_wifi"));
        System.out.println(t.solve(A,B));
    }
}
