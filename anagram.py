def is_anagram(s1, s2):
    s1_cleaned = ''.join(s1.split()).lower()
    s2_cleaned = ''.join(s2.split()).lower()
    return sorted(s1_cleaned) == sorted(s2_cleaned)
