def is_anagram(s1, s2):
    s1_clean = ''.join(sorted(s1.replace(' ', '').lower()))
    s2_clean = ''.join(sorted(s2.replace(' ', '').lower()))
    return s1_clean == s2_clean
