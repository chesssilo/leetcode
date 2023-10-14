// Time complexity: O(n)
// Space complexity: O(n)
var isValid = function(s) {
    const st = [];

    for (let c of s) {
        if (c === '(') {
            st.push(')');
        } else if (c === '{') {
            st.push('}');
        } else if (c === '[') {
            st.push(']');
        } else if (!st.length || st.pop() !== c) {
            return false;
        }
    }
    return !st.length;
}