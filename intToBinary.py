from stack import Stack

number = int(input())
s = Stack()

result = number

while result > 0:
    s.push(result % 2)
    result = result // 2

reversed = ""
while not s.is_empty():
    reversed += str(s.pop())


print(reversed)
print((int(str(reversed), 2)))
