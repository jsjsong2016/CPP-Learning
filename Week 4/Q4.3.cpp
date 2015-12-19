#include <stdlib.h>
#include <cstring>
#include <iostream>
using namespace std;

class BigNumber {
    static int compare(String a, String b) {
        if (a.length() != b.length()) {
            //如果长度不等 通过长度差判断大小
            return a.length() - b.length();
        } else {
            for (int i = 0; i <  a.length(); i++) {
                //如果长度相等 从头比较各位字符 通过字符ASCII码判断大小
                if (a.charAt(i) != b.charAt(i)) {
                    return a.charAt(i) - b.charAt(i);
                }
            }
            //长度和各位数字均相等 返回0表示大小相同
            return 0;
        }
    }

    /**
     * 取相反数
     */
    private static String opposite(String a) {
        //正数添加负号，负数则去除负号
        if (a.charAt(0) == '-') {
            return a.substring(1);
        } else {
            return "-" + a;
        }
    }


    /**
     * 加法运算
     */
    public static String add(String a, String b) {
        //将加数和被加数都转化成正数
        if (a.charAt(0) == '-' && b.charAt(0) == '-') {
            return opposite(add(a.substring(1), b.substring(1)));
        } else if (a.charAt(0) == '-') {
            return subtract(b, a.substring(1));
        } else if (b.charAt(0) == '-') {
            return subtract(a, b.substring(1));
        } else {
            String result = "";
            //通过填充0对齐位置
            while (a.length() < b.length()) {
                a = "0" + a;
            }
            while (a.length() > b.length()) {
                b = "0" + b;
            }
            //设置进位符保存进位情况
            int carry = 0;
            //珠算方法计算各位和 判断是否进位 直到结束
            for (int i = a.length() - 1; i >= 0; i--) {
                int num = (a.charAt(i) - 48) + (b.charAt(i) - 48) + carry;
                if (num >= 10) {
                    num -= 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                result = num + result;
            }
            if (carry == 1) {
                return 1 + result;
            }
            return result;
        }
    }

    /**
     * 减法运算
     */
    public static String subtract(String a, String b) {
        //将减数和被减数都转化成正数 并计算减数和被减数的大小关系
        if (a.charAt(0) == '-' && b.charAt(0) == '-') {
            return opposite(subtract(a.substring(1), b.substring(1)));
        } else if (a.charAt(0) == '-') {
            return opposite(add(a.substring(1), b));
        } else if (b.charAt(0) == '-') {
            return add(a, b.substring(1));
        } else if (compare(a, b) < 0) {
            return opposite(subtract(b, a));
        } else if (compare(a, b) == 0) {
            return "0";
        } else {
            String result = "";
            //通过填充0对齐位置
            while (a.length() < b.length()) {
                a = "0" + a;
            }
            while (a.length() > b.length()) {
                b = "0" + b;
            }
            //设置退位符保存退位情况
            int carry = 0;
            //与加法类似 珠算方法计算各位差 判断是否退位 直到结束
            for (int i = a.length() - 1; i >= 0; i--) {
                int num = (a.charAt(i) - 48) - (b.charAt(i) - 48) - carry;
                if (num < 0) {
                    num += 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                result = num + result;
            }
            if (result.charAt(0) == '0') {
                return result.substring(1);
            }
            return result;
        }
    }

    /**
     * 乘法运算
     */
    public static String multiply(String a, String b) {
        //将乘数和被乘数都转化成正数 并判断乘数和被乘数是否为0
        if ("".equals(b.replaceAll("0", "")) || "".equals(b.replaceAll("0", ""))) {
            return "0";
        } else if (a.charAt(0) == '-' && b.charAt(0) == '-') {
            return multiply(a.substring(1), b.substring(1));
        } else if (a.charAt(0) == '-') {
            return opposite(multiply(a.substring(1), b));
        } else if (b.charAt(0) == '-') {
            return opposite(multiply(a, b.substring(1)));
        } else {
            //循环取乘数的每一个位调用add方法进行累加 循环得出结果  也可以使用珠算方法每位都进行乘法 效率可能更高
            String result = "";
            String inner;
            int num;
            for (int i = 0; i < b.length(); i++) {
                num = b.charAt(i) - 48;
                inner = "0";
                while (num-- > 0) {
                    inner = add(inner, a);
                }
                result = add(result + 0, inner);
            }
            return result;
        }
    }

    /**
     * 除法运算
     */
    public static String divide(String a, String b) {
        //将除数和被除数都转化成正数 并判断除数是否为0
        if ("".equals(b.replaceAll("0", ""))) {
            throw new RuntimeException("除数不能为0");
        } else if (a.charAt(0) == '-' && b.charAt(0) == '-') {
            return divide(a.substring(1), b.substring(1));
        } else if (a.charAt(0) == '-') {
            return opposite(divide(a.substring(1), b));
        } else if (b.charAt(0) == '-') {
            return opposite(divide(a, b.substring(1)));
        } else if (compare(a, b) < 0) {
            return "0";
        } else if (compare(a, b) == 0) {
            return "1";
        } else {
            //与乘法类似 先将除数与被除数对齐 反复调用subtract方法 循环得出结果
            String result = "";
            int num;
            int len = b.length();
            while (a.length() > b.length()) {
                b += "0";
            }
            while (b.length() >= len) {
                num = 0;
                while (compare(a, b) >= 0) {
                    num++;
                    a = subtract(a, b);
                }
                result = result + num;
                b = b.substring(0, b.length() - 1);
            }
            if (result.charAt(0) == '0') {
                return result.substring(1);
            }
            return result;  public class BigNumber {

    /**
     * 比较大小
     */
    private static int compare(String a, String b) {
        if (a.length() != b.length()) {
            //如果长度不等 通过长度差判断大小
            return a.length() - b.length();
        } else {
            for (int i = 0; i <  a.length(); i++) {
                //如果长度相等 从头比较各位字符 通过字符ASCII码判断大小
                if (a.charAt(i) != b.charAt(i)) {
                    return a.charAt(i) - b.charAt(i);
                }
            }
            //长度和各位数字均相等 返回0表示大小相同
            return 0;
        }
    }

    /**
     * 取相反数
     */
    private static String opposite(String a) {
        //正数添加负号，负数则去除负号
        if (a.charAt(0) == '-') {
            return a.substring(1);
        } else {
            return "-" + a;
        }
    }


    /**
     * 加法运算
     */
    public static String add(String a, String b) {
        //将加数和被加数都转化成正数
        if (a.charAt(0) == '-' && b.charAt(0) == '-') {
            return opposite(add(a.substring(1), b.substring(1)));
        } else if (a.charAt(0) == '-') {
            return subtract(b, a.substring(1));
        } else if (b.charAt(0) == '-') {
            return subtract(a, b.substring(1));
        } else {
            String result = "";
            //通过填充0对齐位置
            while (a.length() < b.length()) {
                a = "0" + a;
            }
            while (a.length() > b.length()) {
                b = "0" + b;
            }
            //设置进位符保存进位情况
            int carry = 0;
            //珠算方法计算各位和 判断是否进位 直到结束
            for (int i = a.length() - 1; i >= 0; i--) {
                int num = (a.charAt(i) - 48) + (b.charAt(i) - 48) + carry;
                if (num >= 10) {
                    num -= 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                result = num + result;
            }
            if (carry == 1) {
                return 1 + result;
            }
            return result;
        }
    }

    /**
     * 减法运算
     */
    public static String subtract(String a, String b) {
        //将减数和被减数都转化成正数 并计算减数和被减数的大小关系
        if (a.charAt(0) == '-' && b.charAt(0) == '-') {
            return opposite(subtract(a.substring(1), b.substring(1)));
        } else if (a.charAt(0) == '-') {
            return opposite(add(a.substring(1), b));
        } else if (b.charAt(0) == '-') {
            return add(a, b.substring(1));
        } else if (compare(a, b) < 0) {
            return opposite(subtract(b, a));
        } else if (compare(a, b) == 0) {
            return "0";
        } else {
            String result = "";
            //通过填充0对齐位置
            while (a.length() < b.length()) {
                a = "0" + a;
            }
            while (a.length() > b.length()) {
                b = "0" + b;
            }
            //设置退位符保存退位情况
            int carry = 0;
            //与加法类似 珠算方法计算各位差 判断是否退位 直到结束
            for (int i = a.length() - 1; i >= 0; i--) {
                int num = (a.charAt(i) - 48) - (b.charAt(i) - 48) - carry;
                if (num < 0) {
                    num += 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                result = num + result;
            }
            if (result.charAt(0) == '0') {
                return result.substring(1);
            }
            return result;
        }
    }

    /**
     * 乘法运算
     */
    public static String multiply(String a, String b) {
        //将乘数和被乘数都转化成正数 并判断乘数和被乘数是否为0
        if ("".equals(b.replaceAll("0", "")) || "".equals(b.replaceAll("0", ""))) {
            return "0";
        } else if (a.charAt(0) == '-' && b.charAt(0) == '-') {
            return multiply(a.substring(1), b.substring(1));
        } else if (a.charAt(0) == '-') {
            return opposite(multiply(a.substring(1), b));
        } else if (b.charAt(0) == '-') {
            return opposite(multiply(a, b.substring(1)));
        } else {
            //循环取乘数的每一个位调用add方法进行累加 循环得出结果  也可以使用珠算方法每位都进行乘法 效率可能更高
            String result = "";
            String inner;
            int num;
            for (int i = 0; i < b.length(); i++) {
                num = b.charAt(i) - 48;
                inner = "0";
                while (num-- > 0) {
                    inner = add(inner, a);
                }
                result = add(result + 0, inner);
            }
            return result;
        }
    }

    /**
     * 除法运算
     */
    public static String divide(String a, String b) {
        //将除数和被除数都转化成正数 并判断除数是否为0
        if ("".equals(b.replaceAll("0", ""))) {
            throw new RuntimeException("除数不能为0");
        } else if (a.charAt(0) == '-' && b.charAt(0) == '-') {
            return divide(a.substring(1), b.substring(1));
        } else if (a.charAt(0) == '-') {
            return opposite(divide(a.substring(1), b));
        } else if (b.charAt(0) == '-') {
            return opposite(divide(a, b.substring(1)));
        } else if (compare(a, b) < 0) {
            return "0";
        } else if (compare(a, b) == 0) {
            return "1";
        } else {
            //与乘法类似 先将除数与被除数对齐 反复调用subtract方法 循环得出结果
            String result = "";
            int num;
            int len = b.length();
            while (a.length() > b.length()) {
                b += "0";
            }
            while (b.length() >= len) {
                num = 0;
                while (compare(a, b) >= 0) {
                    num++;
                    a = subtract(a, b);
                }
                result = result + num;
                b = b.substring(0, b.length() - 1);
            }
            if (result.charAt(0) == '0') {
                return result.substring(1);
            }
            return result;
        }
    }
}
        }
    }
}
