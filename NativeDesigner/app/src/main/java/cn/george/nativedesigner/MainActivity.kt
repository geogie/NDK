package cn.george.nativedesigner

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Example of a call to a native method
        sample_text.text = stringFromJNI()
        Log.d("测试-","字符串:${stringFromJNI()}")
        Log.d("测试-","跨库字符串=${customPrint()}")
        Log.d("测试-","加法4+5=${add(4,5)}")
        Log.d("测试-","减法5-4=${sub(5,4)}")
        Log.d("测试-","乘法4*5=${mul(4,5)}")
        Log.d("测试-","除法4/2=${divi(4,2)}")
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String
    external fun customPrint():String
    external fun add(a:Int,b:Int):Int
    external fun sub(a:Int,b:Int):Int
    external fun mul(a:Int,b:Int):Int
    external fun divi(a:Int,b:Int):Int

    companion object {

        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }
}
