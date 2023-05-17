import numpy as np
from matplotlib import pyplot as plt

h,l=.5,45/2/2
Z=np.linspace(0,l,100)
Y=np.linspace(0,h,100)
Ym,Zm=np.meshgrid(Y,Z)

Yp=Ym+.5
Zp=Zm*2/45+.5

Ux = 16*Yp*(1-Yp)*Zp*(1-Zp)

plt.contour(Zm,Ym,Ux)
plt.colorbar()
plt.savefig("inlet_profile.png")

D=np.trapz(np.trapz(Ux,Ym),Z)
S=(20+18.5)*39.375+20*450-1.5*12.25
print(D/S)
