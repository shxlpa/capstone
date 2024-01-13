#---------------------------------------------------------------------
#Name: CalculateMagnet_nolayers.py
#Menu-en: 
#Type: Python
#Create: November 05, 2021 JSOL Corporation
#Comment-en: 
#---------------------------------------------------------------------
# -*- coding: utf-8 -*-
"""


"""

import numpy as np

def calculate(C, MH, R, T):
    
    # Variables (mm)
    # C = emag_core_rad
    # H = Coil Height; coil height = magnet height - estimated shell thickness
        # we are assuming for now that the shell thickness on the sides matches the shell thickenss at the base
        # so i took out the input variable
    H = MH - T
    # MH = emag_height
    # R = Coil Outer Radius
    # T = Shell Thickness
    
    # Wire specs: https://bulkwire.com/magnet-wire
    d = 1.11 #Wire Diameter (18AWG magnet wire with insulation)
    dc = 1.0237 #Wire Diameter (18AWG magnet wire just copper)
    
#    d = 0.706 # 22AWG magnet wire with insulation
#    dc = 0.650 # conductor diameter
#    d = 1.375 # 16AWG magnet wire
#    dc = 1.303 # conductor diameter
    
    f = 0.90 # orthocyclic coil "filling factor"
    rho = 1.68*10**-5 #resistivity of the wire/material in ohms*mm (Copper)
    
    #The Easy, Square Area
    A = H*(R - C) #mm^2
    # The Easy, Cylinder Volume
    V = np.pi*(R**2-C**2)*H #mm^3
    
    ## Coil Specifications
    N = (f*A)/(np.pi*(d/2)**2) #allow N to be non-integer --> this removes discontinuities
    
    ## Power Calculations
    Ac = 0.25 * np.pi * dc**2 #cross-sectional area of copper in the wire
    Vc = f * V #volume occupied by wire
    Lw = Vc / (0.25 * np.pi * d**2) #length of wire (needs to include insulation)
    Rc = rho * Lw/Ac #resistance of the coil
    
    Q = 300 # Constant power condition
    I = np.sqrt(Q/Rc)
    #Q = I**2 * Rc #Heat Generated In Coil
    
    ## Mass Calculations
    rho_cu = 8.96*10**-3 #g/mm^3
    rho_nmx = 7.5*10**-3 #g/mm^3
    rho_ss = 7.7*10**-3 #g/mm^3
    
    # SS400 shell
    H_ss = 40 - np.sqrt(40**2 - (R-36)**2) # Height of SS shell above coil follows a R=40mm circle
    V_ss = np.pi*((R+T)**2 - R**2)*(H + H_ss) #volume of vertical shell
    V_ss = V_ss + np.pi*((R + T)**2)*T #add volume of bottom
    
    M_mag = rho_nmx*(np.pi*(C**2)*MH) #g
    M_cu = rho_cu*(Vc) #g
    M_ss = rho_ss*V_ss #g
    
    M = M_mag + M_cu + M_ss#g

    return I, N, Q, M
