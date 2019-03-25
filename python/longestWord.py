def LongestWord(sen): 
    longest = ""
    for word in sen.split():
        if len(word) > len(longest):
            if word.isalpha():
                longest = word
            elif word.isdigit():
            	longest = word
    
    sen = longest
    return sen
    
print LongestWord(raw_input())