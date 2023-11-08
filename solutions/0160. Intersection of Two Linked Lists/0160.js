// Time complexity: O(n)
// Space complexity: O(1)
var getIntersectionNode = function(headA, headB) {
    let a = headA;
    let b = headB;

    while (a !== b) {
        a = a ? a.next : headB;
        b = b ? b.next : headA;
    }
        
    return a;
};