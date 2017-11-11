
pub fn encode(s : &'static str) -> String {
    format!("1{}1", s)
}

#[cfg(test)]
mod tests {
    use super::encode;
    #[test]
    fn should_encode_a_simple_char() {
        assert_eq!("1A1", encode("A"));
        assert_eq!("1B1", encode("B"));
    }   

    #[test]
    fn should_encode_a_simple_sequence() {
        assert_eq!("1ABC1",encode("ABC"));
        }
}

