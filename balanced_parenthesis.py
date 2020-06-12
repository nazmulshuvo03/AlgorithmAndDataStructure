# importing custom made stack class
from stack import Stack

inputs = input()
conjugates = {'(': ')', ')': '(', '{': '}', '}': '{', '[': ']', ']': '['}
s = Stack()
for i in inputs:
    if s.is_empty():
        s.push(i)
    else:
        if s.peek() == conjugates[str(i)]:
            s.pop()
        else:
            s.push(i)

# print('The Stack is now: ', s.get_stack())
print('Balanced' if len(s.get_stack()) == 0 else 'Unbalanced')
