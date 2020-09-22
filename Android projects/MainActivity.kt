package com.example.calculator_cl

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.TextView
import kotlinx.android.synthetic.main.activity_main.*
import net.objecthunter.exp4j.Expression
import net.objecthunter.exp4j.ExpressionBuilder
import java.lang.Exception

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Number
        val one = findViewById<TextView>(R.id.one)
        val two = findViewById<TextView>(R.id.two)
        val three = findViewById<TextView>(R.id.three)
        val four = findViewById<TextView>(R.id.four)
        val five = findViewById<TextView>(R.id.five)
        val six = findViewById<TextView>(R.id.six)
        val seven = findViewById<TextView>(R.id.seven)
        val eight = findViewById<TextView>(R.id.eight)
        val nine = findViewById<TextView>(R.id.nine)
        val zero = findViewById<TextView>(R.id.zero)

        val add = findViewById<TextView>(R.id.plus)
        val subtract = findViewById<TextView>(R.id.minus)
        val divide = findViewById<TextView>(R.id.divide)
        val multiply = findViewById<TextView>(R.id.multiply)

        val dot = findViewById<TextView>(R.id.decimal)
        val equal = findViewById<TextView>(R.id.equal)
        val input = findViewById<TextView>(R.id.input)
        val output = findViewById<TextView>(R.id.result)
        val delete = findViewById<TextView>(R.id.delete)
        val clear = findViewById<TextView>(R.id.clear)
        val open = findViewById<TextView>(R.id.open)
        val close = findViewById<TextView>(R.id.close)


        one.setOnClickListener {
            evaluateExpression("1", clear = true)
        }

        two.setOnClickListener {
            evaluateExpression("2", clear = true)
        }

        three.setOnClickListener {
            evaluateExpression("3", clear = true)
        }

        four.setOnClickListener {
            evaluateExpression("4", clear = true)
        }

        five.setOnClickListener {
            evaluateExpression("5", clear = true)
        }

        six.setOnClickListener {
            evaluateExpression("6", clear = true)
        }

        seven.setOnClickListener {
            evaluateExpression("7", clear = true)
        }

        eight.setOnClickListener {
            evaluateExpression("8", clear = true)
        }

        nine.setOnClickListener {
            evaluateExpression("9", clear = true)
        }

        zero.setOnClickListener {
            evaluateExpression("0", clear = true)
        }

        dot.setOnClickListener {
            evaluateExpression(".", clear = true)
        }

        //Operators
        add.setOnClickListener {
            evaluateExpression("+", clear = false)
        }

        subtract.setOnClickListener {
            evaluateExpression("-", clear = false)
        }

        divide.setOnClickListener {
            evaluateExpression("/", clear = false)
        }

        multiply.setOnClickListener {
            evaluateExpression("*", clear = false)
        }

        open.setOnClickListener {
            evaluateExpression("(", clear = false)
        }

        close.setOnClickListener {
            evaluateExpression(")", clear = false)
        }

        //all clear
        clear.setOnClickListener {
            input.text = ""
            output.text = ""
        }

        //delete
        delete.setOnClickListener {
            val string = input.text.toString()
            if (string.isNotEmpty()) {
                input.text = string.substring(0, string.length - 1)
            }
            output.text = ""
        }

        equal.setOnClickListener {
            try {
                val expression = ExpressionBuilder(input.text.toString()).build()
                val result = expression.evaluate()
                val longResult = result.toLong()
                if (result == longResult.toDouble()) {
                    output.text = longResult.toString()
                } else
                    output.text = result.toString()

            } catch (e: Exception) {
                Log.d("Exception", " message : " + e.message)
            }
        }
    }


    fun evaluateExpression(string: String, clear: Boolean) {
        val output = findViewById<TextView>(R.id.result)
        val input = findViewById<TextView>(R.id.input)

        if(output.text.isNotEmpty()){
            input.text = ""
        }
        if(clear){
            output.text = ""
            input.append(string)
        } else {
            input.append(output.text)
            input.append(string)
            output.text = ""
        }
    }
}
