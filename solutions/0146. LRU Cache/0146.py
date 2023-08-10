# Time complexity: O(1)
# Space complexity: O(1)
class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None

class DLList:
    def __init__(self):
        self.LRU = Node(None, None)
        self.MRU = Node(None, None)    

        self.LRU.next = self.MRU
        self.MRU.prev = self.LRU

    def remove(self, node):
        node.prev.next, node.next.prev = node.next, node.prev

    def right_add(self, node):
        self.MRU.prev.next, node.prev = node, self.MRU.prev
        node.next, self.MRU.prev = self.MRU, node

    def pop_lru(self):
        lru = self.LRU.next
        self.remove(lru)
        return lru.key  

class LRUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.dll = DLList()
        self.map = dict()

    def get(self, key: int) -> int:
        if key not in self.map:
            return -1
        curr_node = self.map[key]
        val = curr_node.val
        self.dll.remove(curr_node)
        self.dll.right_add(curr_node)
        return val

    def put(self, key: int, value: int) -> None:
        if key in self.map:
            self.dll.remove(self.map[key])
        node = Node(key, value)
        self.map[key] = node 
        self.dll.right_add(node)

        if len(self.map) > self.cap:
            lry_key = self.dll.pop_lru()
            del self.map[lry_key] 