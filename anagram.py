def is_anagram(s1, s2):
    s1 = ''.join(s1.lower().split())
    s2 = ''.join(s2.lower().split())
    return sorted(s1) == sorted(s2)