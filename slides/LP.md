##

$$
\min x_1 + x_2 \\
s.t.\ 3x_1 + 4x_2 \ge 5 \\
6x_1 + 7x_2 \ge 8 \\
x_1, x_2 \ge 0 
$$

拉格朗日函数：

$$
L(x, \lambda_1, \lambda_2, \mu_1, \mu_2) = x_1+x_2 \\
-\lambda_1(3x_1+4x_2-5) \\
-\lambda_2(6x_1+7x_2-8) \\
-\mu_1 x_1 \\
-\mu_2 x_2 \\
= (1-3\lambda_1-6\lambda_2-\mu_1)x_1 + (2-4\lambda_1-7\lambda_2-\mu_2)x_2+5\lambda_1 + 8\lambda_2
$$

求拉格朗日函数的下确界：
$$
g(\lambda_1, \lambda_2) = \inf_{x\in D} L(x_1, x_2, \lambda_1,\lambda_2)
$$

等同于：
$$
\frac{\partial g}{\partial x_1} = 0 \Rightarrow 1-3\lambda_1-6\lambda_2-\mu_1=0 \\
\Rightarrow 1-3\lambda_1-6\lambda_2 = \mu_1\ge0\\
\frac{\partial g}{\partial x_2} = 0 \Rightarrow 2-4\lambda_1-7\lambda_2-\mu_2 = 0\\
\Rightarrow 2-4\lambda_1-7\lambda_2=\mu_2 \ge 0\\
$$

因此

$$
g(\lambda_1, \lambda_2) = 5\lambda_1+8\lambda_2, \\
1-3\lambda_1-6\lambda_2\ge0, \\
2-4\lambda_1-7\lambda_2 \ge 0
$$

令下确界最大，化为对偶问题：

$$
\max 5\lambda_1+8\lambda_2 \\
s.t.\ 3\lambda_1+6\lambda_2\le 1 \\
4\lambda_1+7\lambda_2\le 2
$$
