from cs50 import get_string

text = get_string("Text: ")
letters = 0
words = 1
sentences = 0

for char in text:
    if char.isalpha():
        letters += 1
    if char.isspace():
        words += 1
    if char in ["?", ".", "!"]:
        sentences += 1
    
L = (letters * 100)/words 
S = (sentences * 100)/words

grade = int((0.0588 * L - 0.296 * S - 15.8) + 0.5)

if grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")
