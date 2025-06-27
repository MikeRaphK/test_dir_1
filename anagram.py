def is_anagram(s1, s2):
    # Remove spaces and convert to lower case
    s1 = ''.join(s1.split()).lower()
    s2 = ''.join(s2.split()).lower()
    return sorted(s1) == sorted(s2)
