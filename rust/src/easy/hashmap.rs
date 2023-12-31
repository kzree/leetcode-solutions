use std::{collections::HashMap, i32};

// 383. Ransom Note
fn get_char_counts(string: String) -> HashMap<char, i32> {
    let char_map: HashMap<char, i32> =
        string
            .to_lowercase()
            .chars()
            .fold(HashMap::new(), |mut map, c| {
                *map.entry(c).or_insert(0) += 1;
                map
            });

    char_map
}

pub fn old_can_construct(ransom_note: String, magazine: String) -> bool {
    let ransom_counts = get_char_counts(ransom_note);
    let magazine_counts = get_char_counts(magazine);

    for (c, count) in ransom_counts {
        match magazine_counts.get(&c) {
            Some(magazine_count) => {
                if magazine_count < &count {
                    return false;
                }
            }
            None => return false,
        }
    }
    true
}

pub fn can_construct(ransom_note: String, magazine: String) -> bool {
    let mut magazine_counts = get_char_counts(magazine);

    for c in ransom_note.to_lowercase().chars() {
        if let Some(m) = magazine_counts.get_mut(&c) {
            if *m == 0 {
                return false;
            }
            *m -= 1;
        } else {
            return false;
        }
    }
    true
}
