package main

import (
	"errors"
	"fmt"
	"math"
)

// cd /Users/dabochko/Documents/University/semester5/modeling/lab2 && go run lab2.go

func calculate(x float64) (float64, string, error) {
	if x <= -3 {
		if x > -5 {
			y := math.Log(x + 5)

			return y, "y = ln(x + 5)", nil
		} else {
			return 0, "", errors.New("нарушение ОДЗ: ln(x + 5) не определён")
		}
	} else {
		if x <= 3 {
			if x == 2 || x == -2 {
				return 0, "", errors.New("нарушение ОДЗ: знаменатель x² - 4 равен нулю")
			} else {
				y := (x + 2) / (x*x - 4)

				return y, "y = (x + 2) / (x² - 4)", nil
			}
		} else {
			y := math.Sin(x)

			return y, "y = sin(x)", nil
		}
	}
}

func main() {
	var x float64

	fmt.Print("Введите x: ")

	if _, err := fmt.Scan(&x); err != nil {
		fmt.Println("Ошибка ввода: необходимо ввести число")
		return
	}

	y, mode, err := calculate(x)
	if err != nil {
		fmt.Println("Аварийный останов:", err)
		return
	}

	fmt.Println("Активный режим:", mode)
	fmt.Printf("y = %.6f\n", y)
}
