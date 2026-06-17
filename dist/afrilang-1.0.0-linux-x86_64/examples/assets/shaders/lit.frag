#version 120
varying vec3 vNormal;
uniform vec3 uSunDir;
uniform vec3 uSunColor;
uniform vec3 uAmbient;
void main() {
    float ndl = max(dot(normalize(vNormal), normalize(-uSunDir)), 0.0);
    vec3 color = uAmbient + uSunColor * ndl;
    gl_FragColor = vec4(color, 1.0);
}
