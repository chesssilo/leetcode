// Time complexity: O(n)
// Space complexity: O(1)
function checkIfInstanceOf(obj: any, classFunction: any): boolean {
  while (obj != null) {
    if (obj.constructor === classFunction) {
      return true;
    }
    obj = Object.getPrototypeOf(obj);
  }

  return false;
};