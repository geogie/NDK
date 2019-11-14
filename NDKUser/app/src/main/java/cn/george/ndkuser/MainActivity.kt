package cn.george.ndkuser

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import cn.george.nativecreator.MainActivity

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        Log.d("测试-","打印:${MainActivity().stringFromJNI("-", "-", "~", "X")}")
    }
}
