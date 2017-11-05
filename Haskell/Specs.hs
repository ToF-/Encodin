import Test.Hspec
import Encoding

main = specs

specs = hspec $ do
    describe "encode" $ do
        describe "should encode" $ do
            it "a simple sequence" $ do
                encode "AAA"  `shouldBe` "3A"
                encode "BBBB" `shouldBe` "4B"

            it "a sequence of lenght > 9" $ do
                encode "CCCCCCCCCCCCC" `shouldBe` "9C4C"

            it "sequences of distinct chars" $ do
                encode "DDDDDEE" `shouldBe` "5D2E"

        describe "should enclose" $ do
            it "a sequence of one unique char" $ do
                encode "F" `shouldBe` "1F1" 
                encode "G" `shouldBe` "1G1"
            it "a sequence of unique chars" $ do
                encode "HIJ" `shouldBe` "1HIJ1"
                encode "KLMMM" `shouldBe` "1KL13M"

        describe "should escape" $ do
            it "a 1 in a singleton" $ do
                encode "1" `shouldBe` "1111"
