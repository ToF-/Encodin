import Test.Hspec
import Encoding

main = hspec $ do
    describe "encode" $ do
        it "should encode a 2 to 9 chars sequence" $ do
            encode "AAAA"  `shouldBe` "4A"
        it "should encode a 10 to x chars sequence" $ do
            encode "AAAAAAAAAAAA" `shouldBe` "9A3A"

        it "should encode unique chars between 1s" $ do
            encode "ABC"  `shouldBe` "1ABC1"

        it "should encode unique 1 as escaped" $ do
            encode "1A" `shouldBe` "111A1"
