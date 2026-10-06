package main

import (
	"math"
	"testing"
)

// cd /Users/dabochko/Documents/University/semester5/modeling/lab2 && go test lab2.go lab2_test.go

func TestCalculate(t *testing.T) {
	tests := []struct {
		x       float64
		want    float64
		mode    string
		wantErr string
	}{
		{
			-6,
			0,
			"",
			"нарушение ОДЗ: ln(x + 5) не определён",
		},
		{
			-5,
			0,
			"",
			"нарушение ОДЗ: ln(x + 5) не определён",
		},
		{
			-4,
			math.Log(1),
			"y = ln(x + 5)",
			"",
		},
		{
			-3,
			math.Log(2),
			"y = ln(x + 5)",
			"",
		},
		{
			-2,
			0,
			"",
			"нарушение ОДЗ: знаменатель x² - 4 равен нулю",
		},
		{
			0,
			-0.5,
			"y = (x + 2) / (x² - 4)",
			"",
		},
		{
			2,
			0,
			"",
			"нарушение ОДЗ: знаменатель x² - 4 равен нулю",
		},
		{
			3,
			1,
			"y = (x + 2) / (x² - 4)",
			"",
		},
		{
			4,
			math.Sin(4),
			"y = sin(x)",
			"",
		},
	}

	for _, tt := range tests {
		got, mode, err := calculate(tt.x)

		if tt.wantErr != "" {
			if err == nil {
				t.Errorf("x = %v: ожидалась ошибка %q", tt.x, tt.wantErr)
				continue
			}

			if err.Error() != tt.wantErr {
				t.Errorf("x = %v: получили ошибку %q, ожидали %q", tt.x, err.Error(), tt.wantErr)
			}

			continue
		}

		if err != nil {
			t.Errorf("x = %v: неожиданная ошибка: %v", tt.x, err)
			continue
		}

		if math.Abs(got-tt.want) > 0.000001 {
			t.Errorf("x = %v: получили %v, ожидали %v", tt.x, got, tt.want)
		}

		if mode != tt.mode {
			t.Errorf("x = %v: получили режим %q, ожидали %q", tt.x, mode, tt.mode)
		}
	}
}
