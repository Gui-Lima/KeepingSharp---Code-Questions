package kata
import s "strings"
import "fmt"
import "math"

func Solution(str string) []string {
  counter := 0
  fmt.Println(str)
  returnedValues := make([]string, int(math.Ceil(float64(float64(len(str))/float64(2)))))
  for i:=0;i<len(str);i+=2 {
    if(i+1 < len(str)){
      returnedValues[counter] = s.Join([]string{string(str[i]), string(str[i+1])}, "")
      counter++
    }
  }
  fmt.Println(counter)
  if(len(str) % 2 != 0){
     returnedValues[counter] = s.Join([]string{string(str[len(str) - 1]), "_"}, "")
  }
  return returnedValues
}
