// Time complexity: O(1)
// Space complexity: O(1)
type JSONValue = 
  | null
  | boolean 
  | number 
  | string 
  | JSONValue[] 
  | { [key: string]: JSONValue };

function argumentsLength(...args: JSONValue[]): number {
  return args.length;
};