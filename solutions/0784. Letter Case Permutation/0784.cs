public class Solution {
    List<string> res = new List<string>();
    public IList<string> LetterCasePermutation(string s) {
        Dfs(s, "", 0);
        return res;
    }

    private void Dfs(string s, string current, int id) {
        if(id == s.Length) {
            res.Add(current);
            return;
        }

        if(Char.IsDigit(s[id])) {
            Dfs(s, current + s[id], id + 1);
        } else {
            Dfs(s, current + char.ToUpper(s[id]), id + 1);
            Dfs(s, current + char.ToLower(s[id]), id + 1);
        }
    }
}