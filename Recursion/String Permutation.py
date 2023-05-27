def generate_permutations(string):
    if len(string) == 1:
        return [string]
    
    permutations = []
    for i in range(len(string)):
        first_char = string[i]
        remaining_chars = string[:i] + string[i+1:]
        sub_permutations = generate_permutations(remaining_chars)
        for sub_permutation in sub_permutations:
            permutation = first_char + sub_permutation
            permutations.append(permutation)
    
    return permutations

ans = generate_permutations("abc")
print(len(ans))
for item in ans:
    print(item)