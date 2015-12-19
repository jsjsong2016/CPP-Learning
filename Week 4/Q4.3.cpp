#include <stdlib.h>
#include <cstring>
#include <iostream>
using namespace std;

class BigNumber {
    static int compare(String a, String b) {
        if (a.length() != b.length()) {
            //������Ȳ��� ͨ�����Ȳ��жϴ�С
            return a.length() - b.length();
        } else {
            for (int i = 0; i <  a.length(); i++) {
                //���������� ��ͷ�Ƚϸ�λ�ַ� ͨ���ַ�ASCII���жϴ�С
                if (a.charAt(i) != b.charAt(i)) {
                    return a.charAt(i) - b.charAt(i);
                }
            }
            //���Ⱥ͸�λ���־���� ����0��ʾ��С��ͬ
            return 0;
        }
    }

    /**
     * ȡ�෴��
     */
    private static String opposite(String a) {
        //������Ӹ��ţ�������ȥ������
        if (a.charAt(0) == '-') {
            return a.substring(1);
        } else {
            return "-" + a;
        }
    }


    /**
     * �ӷ�����
     */
    public static String add(String a, String b) {
        //�������ͱ�������ת��������
        if (a.charAt(0) == '-' && b.charAt(0) == '-') {
            return opposite(add(a.substring(1), b.substring(1)));
        } else if (a.charAt(0) == '-') {
            return subtract(b, a.substring(1));
        } else if (b.charAt(0) == '-') {
            return subtract(a, b.substring(1));
        } else {
            String result = "";
            //ͨ�����0����λ��
            while (a.length() < b.length()) {
                a = "0" + a;
            }
            while (a.length() > b.length()) {
                b = "0" + b;
            }
            //���ý�λ�������λ���
            int carry = 0;
            //���㷽�������λ�� �ж��Ƿ��λ ֱ������
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
     * ��������
     */
    public static String subtract(String a, String b) {
        //�������ͱ�������ת�������� ����������ͱ������Ĵ�С��ϵ
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
            //ͨ�����0����λ��
            while (a.length() < b.length()) {
                a = "0" + a;
            }
            while (a.length() > b.length()) {
                b = "0" + b;
            }
            //������λ��������λ���
            int carry = 0;
            //��ӷ����� ���㷽�������λ�� �ж��Ƿ���λ ֱ������
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
     * �˷�����
     */
    public static String multiply(String a, String b) {
        //�������ͱ�������ת�������� ���жϳ����ͱ������Ƿ�Ϊ0
        if ("".equals(b.replaceAll("0", "")) || "".equals(b.replaceAll("0", ""))) {
            return "0";
        } else if (a.charAt(0) == '-' && b.charAt(0) == '-') {
            return multiply(a.substring(1), b.substring(1));
        } else if (a.charAt(0) == '-') {
            return opposite(multiply(a.substring(1), b));
        } else if (b.charAt(0) == '-') {
            return opposite(multiply(a, b.substring(1)));
        } else {
            //ѭ��ȡ������ÿһ��λ����add���������ۼ� ѭ���ó����  Ҳ����ʹ�����㷽��ÿλ�����г˷� Ч�ʿ��ܸ���
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
     * ��������
     */
    public static String divide(String a, String b) {
        //�������ͱ�������ת�������� ���жϳ����Ƿ�Ϊ0
        if ("".equals(b.replaceAll("0", ""))) {
            throw new RuntimeException("��������Ϊ0");
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
            //��˷����� �Ƚ������뱻�������� ��������subtract���� ѭ���ó����
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
     * �Ƚϴ�С
     */
    private static int compare(String a, String b) {
        if (a.length() != b.length()) {
            //������Ȳ��� ͨ�����Ȳ��жϴ�С
            return a.length() - b.length();
        } else {
            for (int i = 0; i <  a.length(); i++) {
                //���������� ��ͷ�Ƚϸ�λ�ַ� ͨ���ַ�ASCII���жϴ�С
                if (a.charAt(i) != b.charAt(i)) {
                    return a.charAt(i) - b.charAt(i);
                }
            }
            //���Ⱥ͸�λ���־���� ����0��ʾ��С��ͬ
            return 0;
        }
    }

    /**
     * ȡ�෴��
     */
    private static String opposite(String a) {
        //������Ӹ��ţ�������ȥ������
        if (a.charAt(0) == '-') {
            return a.substring(1);
        } else {
            return "-" + a;
        }
    }


    /**
     * �ӷ�����
     */
    public static String add(String a, String b) {
        //�������ͱ�������ת��������
        if (a.charAt(0) == '-' && b.charAt(0) == '-') {
            return opposite(add(a.substring(1), b.substring(1)));
        } else if (a.charAt(0) == '-') {
            return subtract(b, a.substring(1));
        } else if (b.charAt(0) == '-') {
            return subtract(a, b.substring(1));
        } else {
            String result = "";
            //ͨ�����0����λ��
            while (a.length() < b.length()) {
                a = "0" + a;
            }
            while (a.length() > b.length()) {
                b = "0" + b;
            }
            //���ý�λ�������λ���
            int carry = 0;
            //���㷽�������λ�� �ж��Ƿ��λ ֱ������
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
     * ��������
     */
    public static String subtract(String a, String b) {
        //�������ͱ�������ת�������� ����������ͱ������Ĵ�С��ϵ
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
            //ͨ�����0����λ��
            while (a.length() < b.length()) {
                a = "0" + a;
            }
            while (a.length() > b.length()) {
                b = "0" + b;
            }
            //������λ��������λ���
            int carry = 0;
            //��ӷ����� ���㷽�������λ�� �ж��Ƿ���λ ֱ������
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
     * �˷�����
     */
    public static String multiply(String a, String b) {
        //�������ͱ�������ת�������� ���жϳ����ͱ������Ƿ�Ϊ0
        if ("".equals(b.replaceAll("0", "")) || "".equals(b.replaceAll("0", ""))) {
            return "0";
        } else if (a.charAt(0) == '-' && b.charAt(0) == '-') {
            return multiply(a.substring(1), b.substring(1));
        } else if (a.charAt(0) == '-') {
            return opposite(multiply(a.substring(1), b));
        } else if (b.charAt(0) == '-') {
            return opposite(multiply(a, b.substring(1)));
        } else {
            //ѭ��ȡ������ÿһ��λ����add���������ۼ� ѭ���ó����  Ҳ����ʹ�����㷽��ÿλ�����г˷� Ч�ʿ��ܸ���
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
     * ��������
     */
    public static String divide(String a, String b) {
        //�������ͱ�������ת�������� ���жϳ����Ƿ�Ϊ0
        if ("".equals(b.replaceAll("0", ""))) {
            throw new RuntimeException("��������Ϊ0");
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
            //��˷����� �Ƚ������뱻�������� ��������subtract���� ѭ���ó����
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
