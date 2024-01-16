# Time complexity: O(1)
# Space complexity: O(n)
class RandomizedSet:
    def __init__(self):
        self.val_to_index = collections.defaultdict(int)
        self.vals = []

    def insert(self, val: int) -> bool:
        if val in self.val_to_index:
            return False
        self.val_to_index[val] = len(self.vals)
        self.vals.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self.val_to_index:
            return False
        index = self.val_to_index[val]
        self.val_to_index[self.vals[-1]] = index
        del self.val_to_index[val]
        self.vals[index] = self.vals[-1]
        self.vals.pop()
        return True
        
    def getRandom(self) -> int:
        index = random.randint(0, len(self.vals) - 1)
        return self.vals[index]  