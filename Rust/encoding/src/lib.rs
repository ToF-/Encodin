
pub fn encode(s : String) -> String {
    let seq : String;
    seq = match s.chars().next() {
        Some('1') => String::from("11"),
        Some(_)   => s,

        None      => s
        };
    format!("1{}1", seq)
}
#[cfg(test)]
mod tests {
    use super::encode;
    #[test]
    fn should_encode_a_simple_char() {
        assert_eq!("1A1", encode(String::from("A")));
        assert_eq!("1B1", encode(String::from("B")));
    }
    #[test]
    fn should_encode_a_sequence_of_unique_chars() {
        assert_eq!("1ABC1", encode(String::from("ABC")));
    }
    #[test]
    fn should_escape_1s_in_a_sequence() {
        assert_eq!("1111", encode(String::from("1")));
    }   
}

