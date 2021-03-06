class Stack():
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def is_empty(self):
        return self.items == []

    def peek(self):
        if not self.is_empty():
            return self.items[-1]

    def get_stack(self):
        return self.items

# s = Stack()
# print(s.is_empty())
# s.push(56)
# s.push(23)
# s.push(30)
# s.push(20)
# print(s.get_stack())
# s.pop()
# print(s.get_stack())
# print(s.is_empty())
# print(s.peek())

