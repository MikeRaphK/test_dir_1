def is_anagram(s1, s2):
    # Normalize the strings by removing spaces and converting to lowercase
    s1 = ''.join(s1.split()).lower()
    s2 = ''.join(s2.split()).lower()
    return sorted(s1) == sorted(s2)