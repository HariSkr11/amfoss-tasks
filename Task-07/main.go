package main

import (
	"strconv"
	"syscall/js"
)

//var Count = 0

// Implement the functions here

// function for converting to int and Increamenting

func Increament(Count string) int {
	return1, err := strconv.Atoi(Count)
	if return1 == 0 {
		return 1
	}
	if err == nil {
		return1++
		return return1
	}
	return return1
}

// function for converting to int and Decreamenting
func decreament(Count string) int {
	return1, err := strconv.Atoi(Count)
	if return1 == 0 {
		return -1
	}
	if err == nil {
		return1--
		return return1
	}
	return return1
}

//FUnctions for connecting to get and return value to JS

func incr(this js.Value, args []js.Value) interface{} {
	doc := js.Global().Get("document")
	value := doc.Call("getElementById", "int")
	var inc_valu = value.Get("innerHTML").String()
	value.Set("innerHTML", Increament(inc_valu))
	return inc_valu
}

func decr(this js.Value, args []js.Value) interface{} {
	doc := js.Global().Get("document")
	value := doc.Call("getElementById", "int")
	var dec_valu = value.Get("innerHTML").String()
	value.Set("innerHTML", decreament(dec_valu))
	return dec_valu
}

func reset(this js.Value, args []js.Value) interface{} {
	doc := js.Global().Get("document")
	value := doc.Call("getElementById", "int")
	value.Set("innerHTML", 0)
	return 0
}

func main() {
	c := make(chan struct{}, 0)
	js.Global().Set("incr", js.FuncOf(incr))
	js.Global().Set("decr", js.FuncOf(decr))
	js.Global().Set("reset", js.FuncOf(reset))
	<-c

}
